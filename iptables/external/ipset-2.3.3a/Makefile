#!/usr/bin/make

######################################################################
# YOU SHOULD NOT NEED TO TOUCH ANYTHING BELOW THIS LINE
######################################################################

ifndef KERNEL_DIR
KERNEL_DIR=/usr/src/linux
endif
ifndef IP_NF_SET_MAX
IP_NF_SET_MAX=256
endif
ifndef IP_NF_SET_HASHSIZE
IP_NF_SET_HASHSIZE=1024
endif

IPSET_VERSION:=2.3.3

PREFIX:=/opt
LIBDIR:=$(PREFIX)/lib
BINDIR:=$(PREFIX)/sbin
MANDIR:=$(PREFIX)/man
INCDIR:=$(PREFIX)/include
IPSET_LIB_DIR:=$(LIBDIR)/ipset

# directory for new iptables releases
RELEASE_DIR:=/tmp

COPT_FLAGS:=-O2
CFLAGS:=$(COPT_FLAGS) -Wall -Wunused -Ikernel/include -I.  #-g -DIPSET_DEBUG #-pg # -DIPTC_DEBUG
SH_CFLAGS:=$(CFLAGS) -fPIC
SETTYPES:=ipmap portmap macipmap iphash nethash iptree iptreemap ipporthash

PROGRAMS=ipset
SHARED_LIBS=$(foreach T, $(SETTYPES),libipset_$(T).so)
INSTALL=$(DESTDIR)$(BINDIR)/ipset $(DESTDIR)$(MANDIR)/man8/ipset.8
INSTALL+=$(foreach T, $(SETTYPES), $(DESTDIR)$(LIBDIR)/ipset/libipset_$(T).so)

all: binaries modules

.PHONY: tests

tests:
	cd tests; ./runtest.sh

binaries: $(PROGRAMS) $(SHARED_LIBS)

binaries_install: binaries $(INSTALL)

patch_kernel:
	cd kernel; ./patch_kernel $(KERNEL_DIR)

modules:
	@[ ! -f $(KERNEL_DIR)/net/ipv4/netfilter/Config.in ] || (echo "Error: The directory '$(KERNEL_DIR)' looks like a Linux 2.4.x kernel source tree, you have to patch it by 'make patch_kernel'." && exit 1)
	@[ -f $(KERNEL_DIR)/net/ipv4/netfilter/Kconfig ] || (echo "Error: The directory '$(KERNEL_DIR)' doesn't look like a Linux 2.6.x kernel source tree." && exit 1)
	@[ -f $(KERNEL_DIR)/.config ] || (echo "Error: The kernel source in '$(KERNEL_DIR)' must be configured" && exit 1)
	@[ -f $(KERNEL_DIR)/Module.symvers ] || echo "Warning: You should run 'make modules' in '$(KERNEL_DIR)' beforehand"
	cd kernel; make -C $(KERNEL_DIR) M=`pwd` IP_NF_SET_MAX=$(IP_NF_SET_MAX) IP_NF_SET_HASHSIZE=$(IP_NF_SET_HASHSIZE) modules

modules_install: modules
	cd kernel; make -C $(KERNEL_DIR) M=`pwd` modules_install

install: binaries_install modules_install

clean: $(EXTRA_CLEANS)
	rm -rf $(PROGRAMS) $(SHARED_LIBS) *.o *~
	[ -f $(KERNEL_DIR)/net/ipv4/netfilter/Config.in ] || (cd kernel; make -C $(KERNEL_DIR) M=`pwd` clean)

#The ipset(8) self
ipset.o: ipset.c
	$(CC) $(CFLAGS) -DIPSET_VERSION=\"$(IPSET_VERSION)\" -DIPSET_LIB_DIR=\"$(IPSET_LIB_DIR)\" -c -o $@ $<

ipset: ipset.o
	$(CC) $(CFLAGS) -ldl -rdynamic -o $@ $^

#Pooltypes
ipset_%.o: ipset_%.c
	$(CC) $(SH_CFLAGS) -o $@ -c $<

libipset_%.so: ipset_%.o
	$(LD) -shared -o $@ $<

$(DESTDIR)$(LIBDIR)/ipset/libipset_%.so: libipset_%.so
	@[ -d $(DESTDIR)$(LIBDIR)/ipset ] || mkdir -p $(DESTDIR)$(LIBDIR)/ipset
	cp $< $@

$(DESTDIR)$(BINDIR)/ipset: ipset
	@[ -d $(DESTDIR)$(BINDIR) ] || mkdir -p $(DESTDIR)$(BINDIR)
	cp $< $@

$(DESTDIR)$(MANDIR)/man8/ipset.8: ipset.8
	@[ -d $(DESTDIR)$(MANDIR)/man8 ] || mkdir -p $(DESTDIR)$(MANDIR)/man8
	cp $< $@
