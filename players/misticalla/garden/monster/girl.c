inherit "/players/whisky/seaworld/monster/monster";
 
reset(arg) {

  ::reset(arg);

  if (!arg) {
  string chat_str;

    chat_str = ({ "The little girl screams loudly.\n",
          "The little girl cries, big tears are rolling down her cheeks.\n",
          "The little girl says: The evil witch has caught my brother.\n",
          "The little girl says: Please free him, I am so lost.\n",
  "The little girl says: But avoid the oven.\n"+
  "This evil oven has killed many adventurers before you, be careful.\n",  
  "The little girl says: We did nothing wrong, we were only hungry.\n",
  "The little girl says: So we ate some gingerbread that was lying around.\n",
  "The little girl says: But then the evil witch came and caught my brother.\n"});
     set_name("girl");
     set_alias("little girl");
     set_short("A little girl");
     load_chat(24,chat_str);
     set_long("The girl is sitting on the path. She looks very sad. \nTears are rolling down her cheeks.\n");
     set_race("human");
     set_gender(2);
     set_level(2);
     set_size(2);
  /* Ethereal Cashimor, 260193, illegal alignment number */
  /* I suggest a call to Padrone's sherrif */
     set_al(2400); /* now 80% reduced hope its ok :) */
  set_al(1000);
     add_money(random(200));
     set_aggressive(0);
     move_object(clone_object("players/misticalla/garden/obj/shawl"),
     this_object());
  }
}
notify(str){ 
  say(str);
  write(str);
  }
follow(str) {
  string who,where;
  if(sscanf(str,"%s leaves %s",who,where) == 2)
  init_command(where);
  }
/* Init commented out by Cashimor, 260193, because of the fact that all the
   commands didn't notify the rest of the players in the room of what
   happened, and because of the inconsistency of the fondle, hug and fuck
   commands. */
#if 0
 init() {
  ::init();
  add_action("comfort","comfort");
  add_action("kiss","kiss");
  add_action("hug","hug");
  add_action("bow","bow");
  add_action("shake","shake");
  }
#endif 0
comfort(str) {
  if (str=="girl" || str=="little girl") {
  write("The little girl leans her head at your shoulder and cries.\n");
  return 1;
 }
}
kiss(str) {
  if (str=="girl" || str=="little girl") {
  write("The little girl kisses you softly.\n");
  return 1;
 }
}
hug(str) {
  if (str=="girl" || str=="little girl") {
  write("The little girl laughs merrily.\n");
  write("The little girl says: You really nice.\n");
  return 1;
 }
}
 bow(str) {
 if (str=="girl" || str=="little girl") {
  write("The little girl stares dreamingly into your eyes.\n");
 return 1;
  }
}
 shake(str) {
  if (str=="girl" || str=="little girl") {
  write("The little girl shakes you fondly.\n");
  return 1;
 }
}

