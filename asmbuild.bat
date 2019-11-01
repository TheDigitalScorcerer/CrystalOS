ubuntu run "sh asmbuild.sh"
qemu-system-i386 -fda kernel.flp -no-reboot -no-shutdown -monitor stdio
::bochs -q -f bochsrc
pause