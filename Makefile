freshplayer: freshplayer-installer.c dev/freshplayer-installer-seeker.c dev/freshplayer-installer-options.c
	cc freshplayer-installer.c -Wall -o freshplayer
	@echo ➼ freshplayer-installer successfully compiled

#install
install: freshplayer
	cp freshplayer /usr/bin
	@echo ➼ freshplayer-installer successfully installed

#uninstall
uninstall: /usr/bin/freshplayer
	rm -R /usr/bin/freshplayer
	@echo ➼ freshplayer-installer successfully uninstalled

#clean
clean: freshplayer
	rm -R freshplayer
	@echo ➼ freshplayer-installer cleaned

#all
all: freshplayer-installer.c dev/freshplayer-installer-seeker.c dev/freshplayer-installer-options.c
	cc freshplayer-installer.c -Wall -o freshplayer
	@echo ➼ freshplayer-installer successfully compiled
	cp freshplayer /usr/bin
	@echo ➼ freshplayer-installer successfully installed
	rm -R freshplayer
	@echo ➼ freshplayer-installer cleaned
