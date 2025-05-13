/* Prison.c 910622 Herp --- New, enhanced prison for nerdy wizards. */
 
/* Once a wizard is put in here, he'll stay here even if he/she is
   teleported out by another wiz, and even after a game crash or
   a shutdown the imprisoned wiz will be put in here again after signing
   on to the game.
 
   The wizard can only be freed by
   A) Me, Herp, the prison-owner, GateKeeper Of Mordor, or
   B) By archwizards and God Himself.
   To free an wizard, remove the shackles he/she/it is wearing.
 
   To imprison wizards, just teleport them here. If a wiz comes in
   here by accident, well ... BAD LUCK !
 
   Remember that the command "in <room> trans <player>" makes a
   temporary move of yourself to the specified location.
   Therefore, if you are not allowed to leave the prison, it will
   happen that you find yourself imprisoned. :-)
 
   Only the prison-owner and archwizards cannot be imprisoned and may
   visit wizards to bring them some bread, and/or some water.
 
*/
 
#include "include/prison.h"
 
short() { return "Maximum security prison cell"; }
 
self() { return this_object(); }
 
long() {
  write("Looking around, you find yourself in a hugh stone cell.\n" +
        "Some oily torches on the wall are the only light source\n" +
        "around here. Far away in the distance there's a heavy\n" +
        "door made of stone, which fits into the walls as if the\n" +
        "cell and the door had grown together.\n");
  if is_allowed
  write("The poor wizards starving here never will get out,\n" +
        "unless a kind soul like you free them. Just go to the\n" +
        "entrance, open the door and remove the shackles from\n" +
        "the immortal to end the punishment.\n");
  else
  write("Aaah, HNIAR HNIAR HNIAR !!!\n" +
        "So, you think you are immortal, do you ?\n" +
        "Well, you won't stay here till Armageddon's Day,\n" +
        "you'll stay here even longer !\n" +
        "Don't expect you'll ever get free, even your wizard friends\n" +
        "can't help you. Remember, death won't end your punishment;\n" +
        "since you are immortal, you won't get outta here to the end\n" +
        "of eternity ...\n");
}
 
reset(arg) { if (!arg) set_light(1000); }
 
init() {
  if (!is_allowed) {
 
     add_action("pris","",1);
 
     if (!present(PCURSE_ID,this_player()))
     move_object(clone_object(PCURSE),this_player());
 
     if (PNAME=="Someone") this_player()->set_vis();
     this_player()->set_title(", imprisoned in Mordor");
     this_player()->set_alignment("starved and exhausted");
     this_player()->set_pretitle(this_player()->query_pretitle());
     this_player()->save_me(0);
 
     return 1;
  }
} /* init() */
 
exit(ob) {
  if (ob && !ob->query_level()>49) {
     if (!present("pcurse",ob)) move_object(clone_object(PCURSE),ob);
     call_out("no_exit",0,ob);
     return;
  }
}
 
no_exit(ob) {
write("no_exit: ");write(ob);write("\n");
write("no_exit: "+file_name(ob)+"\n");
 if (environment(ob)==this_object()) {
    tell_room("players/herp/workroom","EXIT FROM PRISON WITH ENV=OBJ\n");
  /*  call_out("no_exit",0,ob); */ /* Don't ! This might crash the game */
    return;
  }
  imprison(ob);
}
 
imprison(ob) {
object env;
  env=environment(ob);
  tell_room(PRISON,"Suddenly you see "+ob->query_name()+
      " is thrown in by a slimy tentacle.\n");
  tell_object(ob,"You feel something wrapping around your feet.\n");
  move_object(ob,PRISON);
  if (env) tell_room(env,"An ugly slimy tentacle reaches after "+ob->query_name(
)
    + " and drags "+ob->query_objective()+" underground.\n");
  tell_object(ob,"You are thrown back into your enternal prison !\n");
}
 
pris(str) {
 if (query_verb()=="look" || query_verb()=="l") {
    this_player()->look(str);
    return 1;
 }
 
