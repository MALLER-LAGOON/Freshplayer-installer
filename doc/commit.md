###ABOUT THE COMMIT IDENTIFIERS

the commit identifier is a SHA encrypted 40 character chain, which can be find in the url of the same commit
for example:
the commit 107a4de141 corresponds to the very first freshplayer commit
but THE REAL commit identifier is: [107a4de1411de41af45b6a62ff42d12945ffb39e](https://github.com/i-rinat/freshplayerplugin/commit/107a4de1411de41af45b6a62ff42d12945ffb39e)


###HOW TO GET THE FRESHPLAYER COMMIT IDENTIFIER?


first: you go to the commit tree in: [https://github.com/i-rinat/freshplayerplugin/commits](https://github.com/i-rinat/freshplayerplugin/commits) and look for the commit.

Once in there, you have three choices to get the Freshplayer Commit Identifier:

➸ you can click in the paste-like icon, which will copy the SHA code (commit identifier) to the clipboard in one step

➸ you can click in the commit mask (f.e. 107a4de141), which will redirect you to the commit page. now in the redirected page, you go to navigator bar, and look the url. The 40 characters after "<code>https://github.com/i-rinat/freshplayerplugin/commit/</code>" are the commit identifier.

➸ Or simply you can click in the commit mask, which will redirect you to the commit page. Watch the top left of the page, under the button that says "browse files", and there you have the commit identifier in all its magnificence.


Once you have the commit identifier, you can back to the console and do a:
>$ freshplayer -c [SHA commit identifier] install
