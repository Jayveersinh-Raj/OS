#I am writing everything as root thus, I do not have permission issues
#and thus I did not find the neeed to use sudo

#The commands to create a file1.txt with my first name
dd if=/dev/zero of=file1.txt bs=1M count=1

#Adding the above files to the LOFS
mkfs.ext4 /root/week11/file1.txt
mkfs.ext4 /root/week11/file2.txt

#Please include the file ex2.c from the uploaded files 
#Here we compile ex2.c to ex2.out
gcc ex2.c -o ex2

#For running ex2
./ex2

#The commands for creating a chroot environment
chr=/root/rootTest

#The directory doesn’t exist, we need to create it. We can do that with this command. The -p (parents) option ensures any missing parent directories are created at the same time
mkdir -p $chr

#We need to create directories to hold the portions of the operating system our chroot environment will require.
#We’re going to set up a minimalist Linux environment that uses Bash as the interactive shell. We’ll also include the touch, rm, and ls commands. That will allow us to use all Bash’s built-in commands and touch, rm, and ls. We’ll be able to create, list and remove files, and use Bash
mkdir -p $chr/{bin,lib,lib64}

#Now we’ll change directory into our new root directory
cd $chr

#Lets copy the binaries we will require from your ordinary /bin directory to our chroot /bin directory. The -v (verbose) option causes cp to inform us what it's doing as it copies each file.
cp -v /bin/{bash,touch,ls,rm} $chr/bin

#There will be dependencies in these binaries. We will need to figure out what they are and put those files into our environment as well, else bash, touch, rm, and ls would not work. This must be done for each of our specified instructions in turn. We'll start with Bash. The ldd tool will provide us with a list of dependencies.
ldd /bin/bash

#We need to copy those files into our new environment. Picking the details out of that listing and copying them one at a time is going to be time-consuming and error-prone
list="$(ldd /bin/bash | egrep -o '/lib.*\.[0-9]')"

#We can check the contents of the list using echo
echo $list

#The -v (verbose) option causes cp to announce each copy as it performs it.  The --parents option ensures any missing parent directories are created in the chroot environment
for i in $list; do cp -v --parents "$i" "${chr}"; done

list="$(ldd /bin/touch | egrep -o '/lib.*\.[0-9]')"

#We can now repeat the exact same loop command as before
for i in $list; do cp -v --parents "$i" "${chr}"; done
#And our files are copied for us

#We can now edit the list command line for ls
list="$(ldd /bin/ls | egrep -o '/lib.*\.[0-9]')"

#We'll use the loop command once again. It makes no difference which files are on the list. It copies the files for us as it goes through the list.
for i in $list; do cp -v --parents "$i" "${chr}"; done
#And the dependencies for ls are copied over for us

#We edit the list command line for the last time, making it work for rm
list="$(ldd /bin/ls | egrep -o '/lib.*\.[0-9]')"

#We use the looping copy command one last time
for i in $list; do cp -v --parents "$i" "${chr}"; done

#Our final set of dependencies is transferred to our chroot environment. We've finally arrived at the point where we can use the chroot command. This command establishes the chroot environments root and specifies the shell program to use.
sudo chroot $chr /bin/bash

#To run and check your c program to display contents of the root
./ex2.c



