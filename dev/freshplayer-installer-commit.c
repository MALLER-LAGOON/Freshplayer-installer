void COMMIT_MSG(void);
void COMMIT_DWLD(void);

void COMMIT_MSG(void)
{
	printf( "\nthe commit key is a SHA encrypted 40 character chain, which can be find in the url of the same commit\n"
			"for example:\n"
			"the commit \x1b[1;31m107a4de141\x1b[0;0m corresponds to the very first freshplayer commit\n"
			"but THE REAL commit identifier is: \x1b[1;32m107a4de1411de41af45b6a62ff42d12945ffb39e\x1b[0;0m\n\n"
			"\t\x1b[1;33m¿HOW TO GET THE FRESHPLAYER COMMIT IDENTIFIER?\x1b[0;0m\n\n"
			"first: you go to the commit tree in: \x1b[1;32mhttps://github.com/i-rinat/freshplayerplugin/commits\x1b[0;0m and look for the commit\n"
			"now you have two choices:\n\n"
			"\t➸ you can click in the paste-like icon, which will copy the SHA code (identifier) to the clipboard in one step\n\n"
			"\t➸ you can click in the commit identifier (f.e. 107a4de141), which will redirect you to the commit page.\n"
			"\t  now in the redirected page, you go to navigator bar, and look the url. The 40 characters after \n"
			"\t  \"\x1b[1;33mhttps://github.com/i-rinat/freshplayerplugin/commit/\x1b[0;0m\" are the commit identifier.\n\n"
			"\t➸ Or simply you can click in the commit mask, which will redirect you to the commit page. Watch the\n"
			"\t  top left of the page, under the button that says \"browse files\", and there you have the commit identifier\n"
			"\t  in all its magnificence.\n\n"
			"Once you have the commit identifier, you can back here to the console and do a:\n\n"
			"\t\t\x1b[1;33m$ \x1b[1;32mfreshplayer -c \x1b[1;31m[SHA commit identifier]\x1b[0;0m\n\n");
}

void COMMIT_DWLD(void)
{
	printf("\n\n\t\x1b[1;31mThis part is still work in progress\x1b[0;0m\n\n\n");
}