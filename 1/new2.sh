#!/bin/bash
cd newk2
cd linux-5.19.9
make
make modules
make modules_install
cp -v arch/x86/boot/bzImage /boot/vmlinuz-linux_hocus_pocus_3

ls /usr/lib/modules
mkinitcpio -k 5.19.9 -g /boot/initramfs-linux_hocus_pocus_3.img
grub-mkconfig -o /boot/grub/grub.cfg
cd ..
cd ..