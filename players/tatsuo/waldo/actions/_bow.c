#define TP this_player()
 int _bow(string arg){

 object target;
if(!arg){
say("Humbley, "+TP->query_name()+" bows in the style of "+
"Clan Sunsu, of the House of Shimabuku.\n");

write("You bow in the ancient style of the Clan Sunsu "+
      "of the House of Shimabuku.\n");
return 1;
}
else

target = present(arg,environment(TP) );
 if(!target) return printf(capitalize(arg) + " is not here.\n"),1;

tell_object(target, TP->query_name()+" bows honorably to you in the style\n"+
            "of "+TP->query_possessive()+" great ancestors of Clan "+
            "Sunsu of the House of Shimabuku.\n");
write("You bow honorably to "+arg+" in the style of your ancestors.\n");
say(TP->query_name()+" bows honorably to "+arg+" in the style of\n"+
    TP->query_possessive()+" ancestors of the Clan Sunsu of the\n"+
    "House of Shimabuku.\n", target);
return 1;
}





