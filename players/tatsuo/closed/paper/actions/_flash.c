#define TP this_player()

int _flash(string arg){

if(!arg) return 0;
if(arg != "credentials") return 0;

say(this_player()->query_name()+" flashes "+TP->query_possessive()+" Mission Statments Credentials, "+
"proving what a cool frood "+TP->query_pronoun()+" is!\n");

write("You whip out your Mission Statement credentials flashing them around for all to see, They stand amazed.\n");
return 1;
}

