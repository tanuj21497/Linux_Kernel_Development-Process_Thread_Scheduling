#!/bin/bash
cd newk1
cd linux-5.19.9
make
make modules
make modules_install
cp -v arch/x86/boot/bzImage /boot/vmlinuz-linux_hocus_pocus_2

ls /usr/lib/modules
mkinitcpio -k 5.19.9 -g /boot/initramfs-linux_hocus_pocus_2.img
grub-mkconfig -o /boot/grub/grub.cfg
cd ..
cd ..