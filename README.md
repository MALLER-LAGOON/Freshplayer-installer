##FRESHPLAYER-INSTALLER


Freshplayer-installer is a simple C script that manages the download, compiling and install of I-Rinat's Freshplayerplugin from it's official GitHub repository.

It has nothing special, this script it's just A HELL REALLY BASIC ALMOST BEGINNERS LEVEL, but finally do his thing.

This was done because of the laziness of cloning/download & unzip and compile the project every time to install and/or upgrade, performing a script to do everything for me in one call. This liked to a friend of mine who test it, and he suggested me that upload it somewhere, because he found it very good, and voilá.


###USAGE:

It's as simple as typing:

>$ freshplayer install

it no needs ROOT privileges, and it installs the freshplayerplugin to the current user that do the calls.

###INSTALLING FRESHPLAYER-INSTALLER:

To the Rookies, the folder Deb-packages have the .deb packages to install the software directly with Gdebi or dpkg according your preference.



but, if u want to install it directly from the source code. It's as simple as typing:

>$ sudo make all

And the make will compile and install the Freshplayer-installer

###DEPENDENCIES:

Sinces it's just a simple Ansi C script, it has no especial compiling needs, but to work it needs wget and unzip installed, which usually are installed by default, and it has obviously needs the same dependencies that freshplayerplugin to compile the freshplayerplugin, because magic doesn't really exist (yeah, face that truth!!!):

> $ sudo apt-get install wget unzip cmake pkg-config ragel libasound2-dev libglib2.0-dev libconfig-dev libpango1.0-dev libegl1-mesa-dev libevent-dev libgtk+2.0-dev libgles2-mesa-dev

On Debian the package <code>libgtk+2.0-dev</code> is called <code>libgtk2.0-dev</code>, but usually the apt-get performs the package approval by it self.

<code>THIS IS JUST TO HELP YOU TO MANAGE THE DOWNLOAD AND INSTALL THE LATEST FRESHPLAYER AVAILABLE ON I-RINAT'S GITHUB TO YOUR SYSTEM, FRESHPLAYER-INSTALLER IS NOT AN UPDATE SEEKER.</code>

###THANKS TO:

I-Rinat, your freshplayerplugin is a bless, i'm just one of a thousands fans of your creation. And like i said before: 
# YOU ARE THE BEST!!!
