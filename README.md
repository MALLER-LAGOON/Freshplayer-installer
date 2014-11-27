##FRESHPLAYER-INSTALLER


Freshplayer-installer is a simple C script that manages the download, compiling and install of I-Rinat Freshplayerplugin from its official GitHub repository.

It has nothing special, and the script it's just A WAY REALLY BASIC, but it do his thing.

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

Sinces it's just a simple Ansi C script, it has no especial compiling needs, but to work it needs wget and unzip installed, which usually are installed by default, and it has obviously the same dependencies that freshplayerplugin has:

> $ sudo apt-get install wget unzip cmake pkg-config ragel libasound2-dev libglib2.0-dev libconfig-dev libpango1.0-dev libegl1-mesa-dev libevent-dev libgtk+2.0-dev libgles2-mesa-dev

On Debian the package <code>libgtk+2.0-dev</code> is called <code>libgtk2.0-dev</code>, but usually the apt-get performs the package approval by it self.

<code>THIS IS JUST TO HELP YOU TO MANAGE THE DOWNLOAD AND INSTALL THE LAST FRESHPLAYER AVAILABLE, ON YOUR SYSTEM, FRESHPLAYER-INSTALLER IS NOT AN UPDATE SEEKER.</code>
