ubuntu run "sh asmbuild.sh"
::qemu-system-i386 -fda kernel.flp -no-reboot -no-shutdown -monitor stdio
qemu-system-i386 -cdrom kernel.iso -no-reboot -no-shutdown -monitor stdio
pause