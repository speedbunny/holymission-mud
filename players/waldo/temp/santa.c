inherit "/obj/monster";
 
string chat1;
reset (arg) {
  ::reset(arg);
  if (!arg)
  {
    set_name("santa");
    set_alias("santa klaus");
    set_short("Santa Klaus");
    set_long("This is SANTA KLAUS. The jolliest person around these parts.\n"+
             "You feel the Artic chill eminating from his thick red coat.\n"+
             "You can see his beady eyes behind his thick white beard, and\n"+
             "you feel that attacking this person would be a REALLY BAD IDEA!\n");
    set_race("human");
    set_level(999);
    set_ac(1000);
    set_wc(1000);
    set_al(100);
    set_aggressive(0);
    if (!chat1)
    {
      chat1=allocate(3);
      chat1[0]="Santa Klaus sings : We wish you a Merry Christmas.\n";
      chat1[1]="Santa Klaus sings : And a Happy New Year.\n";
      chat1[2]="You hear a bell ringing in the distance.\n";
      }
    load_chat(4,chat1);
    }
  }
