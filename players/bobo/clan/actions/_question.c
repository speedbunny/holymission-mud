
int _question(string arg){

if (!arg && arg != "amulet") {
   printf("You can ask the amulet about what it can do.\n");
   return (1);
   }
write(

"Before there was civilization, before there was man, there\n"+
"was the sun.  The sun gives life to all those who are in this\n"+
"realm and for that reason the smart people worship it.  This\n"+
"small, hearty clan is filled with beings who are dedicated to\n"+
"the glorification of the sun.  It gives us life, it gives us\n"+
"energy, and it just feels darn good.  As a member of this\n"+
"clan you should go forth among the masses and spread the word\n"+
"that the sun is wonderful and we should give it praise.\n\n"+

"    Clan Commands: cl, cm (message), clanoff, question amulet\n"+
"                   petition, and suggestion.\n"+

"    Clan Emotes: bask, blind, boast, chide, flog, huh, ignore,\n"+
"                 listen, mumble, nourish, pat, settitle, sit,\n"+
"                 wait, worship, and wpose.\n");
return 1;
}
