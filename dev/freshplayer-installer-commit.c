/*The MIT License (MIT)
 *
 *Copyright (c) 2014-2015 MALLER
 *
 *Permission is hereby granted, free of charge, to any person obtaining a copy
 *of this software and associated documentation files (the "Software"), to deal
 *in the Software without restriction, including without limitation the rights
 *to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *copies of the Software, and to permit persons to whom the Software is
 *furnished to do so, subject to the following conditions:
 *
 *The above copyright notice and this permission notice shall be included in all
 *copies or substantial portions of the Software.
 *
 *THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *SOFTWARE.
 */

#define FRESHPLAYER_URL_MAXLENGHT 5000

void COMMIT_MSG(void);
void COMMIT_DWLD(char *commit);

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

void COMMIT_DWLD(char *commit)
{
	char COMMIT_url1[]="https://github.com/i-rinat/freshplayerplugin/archive/";
	char COMMIT_zip[]=".zip";

	char COMMIT_install_chain1[]="echo && echo CREATING TEMPORAL FOLDER... && echo && cd ~ && mkdir freshplayerplugin && cd freshplayerplugin && echo DOWNLOADING SOURCE CODE... && echo && wget ";
	char COMMIT_install_chain2[]=" && echo UNCOMPRESSING SOURCE FILES... && echo && unzip ";
	char COMMIT_install_chain3[]=" && cd freshplayerplugin-";
	char COMMIT_install_chain4[]=" && mkdir build && cd build && echo && echo VERIFYING DEPENDENCIES AND CREATING MAKEFILE... && echo && cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo -DHAVE_PULSEAUDIO=1 .. && echo && echo CREATING FRESHPLAYER PLUGIN... && echo && make && echo && echo INSTALLING FRESHPLAYER PLUGIN... && echo && cp -f libfreshwrapper-pepperflash.so ~/.mozilla/plugins/libfreshwrapper-pepperflash.so && echo && echo REMOVING TEMPORAL FILES... && echo && cd .. && cd .. && cd .. && rm -R freshplayerplugin/ && echo && echo FRESHPLAYER HAS BEEN SUCCESSFULLY INSTALLED &&echo";

	char COMMIT_zip_file[FRESHPLAYER_URL_MAXLENGHT];
	char COMMIT_url[FRESHPLAYER_URL_MAXLENGHT];
	char COMMIT_install[FRESHPLAYER_URL_MAXLENGHT];

	int loopy=53;
	int commit_lenght=40;
	int counter, COMMIT_int;

	counter=loopy+strlen(commit);

	strcpy(COMMIT_url,COMMIT_url1);

	strcpy(COMMIT_zip_file, commit);

	for(COMMIT_int=0;COMMIT_int<=commit_lenght;COMMIT_int++)
	{
		strcpy(&COMMIT_zip_file[40+COMMIT_int],&COMMIT_zip[COMMIT_int]);
	}

	for(COMMIT_int=0;loopy<=counter-1;loopy++, COMMIT_int++)
	{
		strcpy(&COMMIT_url[loopy],&COMMIT_zip_file[COMMIT_int]);
	}

	strcpy(COMMIT_install,COMMIT_install_chain1);

	for(COMMIT_int=0;COMMIT_int<=strlen(COMMIT_url);COMMIT_int++)
	{
		strcpy(&COMMIT_install[159+COMMIT_int], &COMMIT_url[COMMIT_int]);
	}

	for(COMMIT_int=0;COMMIT_int<=56;COMMIT_int++)
	{
		strcpy(&COMMIT_install[256+COMMIT_int], &COMMIT_install_chain2[COMMIT_int]);
	}

	for(COMMIT_int=0;COMMIT_int<=44;COMMIT_int++)
	{
		strcpy(&COMMIT_install[312+COMMIT_int], &COMMIT_zip_file[COMMIT_int]);/**/
	}
	

	for(COMMIT_int=0;COMMIT_int<=25;COMMIT_int++)
	{
		strcpy(&COMMIT_install[356+COMMIT_int], &COMMIT_install_chain3[COMMIT_int]);
	}

	for(COMMIT_int=0;COMMIT_int<=40;COMMIT_int++)
	{
		strcpy(&COMMIT_install[381+COMMIT_int], &commit[COMMIT_int]);
	}

	for(COMMIT_int=0;COMMIT_int<=969;COMMIT_int++)
	{
		strcpy(&COMMIT_install[421+COMMIT_int], &COMMIT_install_chain4[COMMIT_int]);
	}

	system(COMMIT_install);
}
