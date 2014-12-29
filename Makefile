freshplayer: freshplayer-installer.c
	cc freshplayer-installer.c -o freshplayer
	@echo ➼ freshplayer-installer successfully compiled

#install
install:
	cp freshplayer /usr/bin
	@echo ➼ freshplayer-installer successfully installed

#uninstall
uninstall:
	rm /usr/bin/freshplayer
	@echo ➼ freshplayer-installer successfully uninstalled

#clean
clean:
	rm freshplayer
	@echo ➼ freshplayer-installer cleaned

#all
all: freshplayer-installer.c
	cc freshplayer-installer.c -o freshplayer
	@echo ➼ freshplayer-installer successfully compiled
	cp freshplayer /usr/bin
	@echo ➼ freshplayer-installer successfully installed
	rm freshplayer
	@echo ➼ freshplayer-installer cleaned

