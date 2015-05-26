void INSTALL(void);
void INSTALL_GTK3(void);
void UNINSTALL(void);
void INSTALL_FLASH(void);

void INSTALL(void)
{
	char install[]="echo && echo CREATING TEMPORAL FOLDER... && echo && cd ~ && mkdir freshplayerplugin && cd freshplayerplugin && echo DOWNLOADING SOURCE CODE... && echo && wget https://github.com/i-rinat/freshplayerplugin/archive/master.zip && echo UNCOMPRESSING SOURCE FILES... && echo && unzip master.zip && cd freshplayerplugin-master && mkdir build && cd build && echo && echo VERIFYING DEPENDENCIES AND CREATING MAKEFILE... && echo && cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo .. && echo && echo CREATING FRESHPLAYER PLUGIN... && echo && make && echo && echo INSTALLING FRESHPLAYER PLUGIN... && echo && cp -f libfreshwrapper-pepperflash.so ~/.mozilla/plugins/libfreshwrapper-pepperflash.so && echo && echo REMOVING TEMPORAL FILES... && echo && cd .. && cd .. && cd .. && rm -R freshplayerplugin/ && echo && echo FRESHPLAYER HAS BEEN SUCCESSFULLY INSTALLED &&echo";
	system(install);
}

void INSTALL_GTK3(void)
{
	char install[]="echo && echo CREATING TEMPORAL FOLDER... && echo && cd ~ && mkdir freshplayerplugin && cd freshplayerplugin && echo DOWNLOADING SOURCE CODE... && echo && wget https://github.com/i-rinat/freshplayerplugin/archive/master.zip && echo UNCOMPRESSING SOURCE FILES... && echo && unzip master.zip && cd freshplayerplugin-master && mkdir build && cd build && echo && echo VERIFYING DEPENDENCIES AND CREATING MAKEFILE... && echo && cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo -DWITH_GTK=3 .. && echo && echo CREATING FRESHPLAYER PLUGIN... && echo && make && echo && echo INSTALLING FRESHPLAYER PLUGIN... && echo && cp -f libfreshwrapper-pepperflash.so ~/.mozilla/plugins/libfreshwrapper-pepperflash.so && echo && echo REMOVING TEMPORAL FILES... && echo && cd .. && cd .. && cd .. && rm -R freshplayerplugin/ && echo && echo FRESHPLAYER HAS BEEN SUCCESSFULLY INSTALLED &&echo";
	system(install);
}

void UNINSTALL(void)
{
	char uninstall[]="rm -f ~/.mozilla/plugins/libfreshwrapper-pepperflash.so";
	system(uninstall);
}

void INSTALL_FLASH(void)
{
	char install_flash[]="apt-get install flashplugin-nonfree";
	system(install_flash);
}