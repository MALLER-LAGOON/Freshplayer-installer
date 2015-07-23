##FRESHPLAYER-INSTALLER


Freshplayer-installer is a simple C script that manages the download, compiling and install of I-Rinat's Freshplayerplugin from it's [Official GitHub repository](https://github.com/i-rinat/freshplayerplugin).

It has nothing special, mostly do some strings arrangements, but finally do his thing.

This was done because of the laziness of cloning/download & unzip and compile the project every time to install and/or upgrade, performing a script to do everything for me in one call. This liked to a friend of mine who test it, and he suggested me that upload it somewhere, because he found it very good, and voilá.


###USAGE:

It's as simple as typing:

>$ freshplayer install

it no needs ROOT privileges, and it installs the freshplayerplugin to the current user that do the calls.

>$ freshplayer uninstall

obviously uninstalls the freshplayer on the current user.

If, for several reasons, you want to install any other different commit than the latest update of the master branch of the freshplayer, you can do it by typing:

>$ freshplayer --commit [commit identifier] install

or 

>$ freshplayer -c [commit identifier] install

in that way, the freshplayer-installer will seek in the commit tree for the version that u asked, and when find it do his thing.

if you want to know more about how to get the commit identifier, [please read here](https://github.com/MALLER-LAGOON/Freshplayer-installer/blob/master/doc/commit.md).

there is also some parameters that allows to compile the freshplayerplugin with some custom features:

-<code>gtk3</code> = activate gtk3 libraries for compilation instead the gtk2. (recomended for compatibility in new environments)

-<code>debug</code> = compile the freshplayerplugin in debug mode.(WARNING: with this plugin mode, is recommended to open firefox with a file saving mode: <code>$firefox &#62; ~/Desktop/freshtrace.file</code>, because the debug info could easily get &#62;&#62;100M)

-<code>trace</code> = compile the freshplayerplugin in trace mode (WARNING: with this plugin mode, is recommended to open firefox with a file saving mode: <code>$firefox &#62; ~/Desktop/freshtrace.file</code>, because the trace easily can get &#62;&#62;100M)

-<code>angle/gles2/gles/gl</code> = any of this options activates the OpenGL rendering using the ANGLE libraries (not recommended unless necessary, the target freshplayerplugin will be very heavy ~19M, and the performance will be very low, turning the browser very laggy)

-<code>pulse</code> = this option activates the pulseaudio.

-<code>hwdec</code> = activates the hardware aceleration. (even if you apply this option, it is necessary to add <code>enable_hwdec=1</code> in the <code>~/.config/freshwrapper.conf</code> file)

-<code>-commit/c</code> = any of this options looks for a particular commit in the repository, and installs it.

all this parameters has to be used between "freshplayer" and "install"

>$freshplayer -gtk3 -debug -angle install



in the case of the commit install:

>$freshplayer --commit [SHA commit identifier] install

or

>$freshplayer -c [SHA commit identifier] install

it's necessary to put the [SHA commit identifier] inmediately after the -c/--commit, otherwise freshplayer-installer will not recognise the parameter and will finish the process.

if you want to know more about how to get the commit identifier, [please read here](https://github.com/MALLER-LAGOON/Freshplayer-installer/blob/master/doc/commit.md).

###INSTALLING FRESHPLAYER-INSTALLER:


It's as simple as typing:

>$ sudo make all

And the make will compile and install the Freshplayer-installer

###DEPENDENCIES:

Sinces it's just a simple Ansi C script, it has no especial compiling needs, but to work it needs wget and unzip installed, which usually are installed by default, and it has obviously needs the same dependencies that freshplayerplugin to compile the freshplayerplugin, because magic doesn't really exist (yeah, face that truth!!!):

> $ sudo apt-get install wget unzip cmake pkg-config ragel libasound2-dev libssl-dev libglib2.0-dev libconfig-dev libpango1.0-dev libgl1-mesa-dev libevent-dev libgtk2.0-dev libgtk-3-dev libgles2-mesa-dev libxrandr-dev g++ libpulse-dev libxrender-dev libxcursor-dev libv4l-dev libgles2-mesa-dev libavcodec-dev libva-dev libvdpau-dev 

On Debian the package <code>libgtk+2.0-dev</code> is called <code>libgtk2.0-dev</code>, but usually the apt-get performs the package approval by it self.

<code>THIS IS JUST TO HELP YOU TO MANAGE THE DOWNLOAD, COMPILATION AND INSTALL THE LATEST FRESHPLAYER AVAILABLE ON I-RINAT'S GITHUB TO YOUR SYSTEM, FRESHPLAYER-INSTALLER IS NOT AN UPDATE SEEKER.</code>

###THANKS TO:

I-Rinat, your freshplayerplugin is a bless, i'm just one of a thousands fans of your creation. And like i said before: 
# YOU ARE THE BEST!!!
