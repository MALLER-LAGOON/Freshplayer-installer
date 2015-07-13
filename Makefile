freshplayer: freshplayer-installer.c
	cc freshplayer-installer.c -Wall -o freshplayer
	@echo ➼ freshplayer-installer successfully compiled

#install
install:
	cp freshplayer /usr/bin
	@echo ➼ freshplayer-installer successfully installed

#uninstall
uninstall:
	rm -R /usr/bin/freshplayer
	@echo ➼ freshplayer-installer successfully uninstalled

#clean
clean:
	rm -R freshplayer
	@echo ➼ freshplayer-installer cleaned

#all
all: freshplayer-installer.c
	cc freshplayer-installer.c -Wall -o freshplayer
	@echo ➼ freshplayer-installer successfully compiled
	cp freshplayer /usr/bin
	@echo ➼ freshplayer-installer successfully installed
	rm -R freshplayer
	@echo ➼ freshplayer-installer cleaned
