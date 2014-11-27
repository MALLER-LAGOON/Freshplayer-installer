freshplayer: freshplayer-installer.c
	cc freshplayer-installer.c -o freshplayer
	@echo ➼ freshplayer-webinstall successfully compiled

#install
install:
	cp freshplayer /usr/bin
	@echo ➼ freshplayer-webinstall successfully installed

#uninstall
uninstall:
	rm /usr/bin/freshplayer
	@echo ➼ freshplayer-webinstall successfully uninstalled

#clean
clean:
	rm freshplayer
	@echo ➼ freshplayer-webinstall cleaned

#all
all: freshplayer-installer.c
	cc freshplayer-installer.c -o freshplayer
	@echo ➼ freshplayer-webinstall successfully compiled
	cp freshplayer /usr/bin
	@echo ➼ freshplayer-webinstall successfully installed

