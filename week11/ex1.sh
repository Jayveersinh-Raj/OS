#It should be noted that I am using root user directory and didn't 
#required permission, hence non of my commands contains sudo

#At first we'll make a directory week11 and store everything inside it
mkdir week11
cd week 11

#The commands to create a file named lofs.img that is >= 50MB
dd if=/dev/zero of=lofs.img bs=5M count=10
#The commands to check the size of the created file
du -sh lofs.img 

#The commands to create the loop device
losetup -fP lofs.img
#The commands to print the loop device generated 
losetup -a

#The commands to create the filesystem (ext4 in this case)
mkfs.ext4 /root/week11/lofs.img

#The commands to mount the loopback filesystem
#Creating directory lofsdisk first
mkdir /lofsdisk
mount -o loop /dev/loop0 /lofsdisk

#Commands to  Verify the size of the new mount point and type of filesystem 
df -hP /lofsdisk/
mount | grep lofsdisk




