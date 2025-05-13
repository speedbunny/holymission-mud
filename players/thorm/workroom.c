/* DEF_WORKROOM.C */
/* 300693: Ethereal Cashimor: Removed double define for NAME */

inherit "room/room";

#define NAME	"thorm"
#define CNAME   capitalize(NAME)

/* This procedure is called every hour at the mom. The first time it
   is call with the arg==0, after that arg is always 1. */

reset(arg) 
{
  /* do the following block only the first time !! */
  if(!arg)
  {
    /* first we need some light in here */
    set_light(1);

    /* then lets set a short description in case we are in brief-mode */
   short_desc=CNAME + "'s workroom",

    /* now the long standard room description */
    /* change this to fit your style *grin* */
    long_desc="This is the workroom of "+CNAME+".\n" +
              "This room seems quite strange...\n" +
              "You see an oracle standing between the windows. " +
              "There is a small golden " +
              "chest with the symbol of the Armond clan on it.\n";

    /* we need some exits too ... lets set the destination directions */
    dest_dir=({
               "room/post", "post",
               "room/church", "church",
               "room/adv_guild", "guild", 
              });

    /* here could follow some item descriptions, like ...*/
    items=({ 
            "air","It's very thin up here",
            "floor","The floor is dirty",
            "chest","This is the royal chest of the once famous Armond clan",
            "symbol","Three connecting circles, representing the Order, " +
                     "the Chaos and the Equilibrium",
            "oracle","This is the Crystalic Oracle of Thorm of the Armond " +
                     "clan",
            "window","You can see the Dracholic's mountain to the north, " +
                     "the Silver Lands to the east and the Mage Tower to " +
                     "the south",
           });
              
    /* Properties can be set like the following */
    property = ({
                 "no_teleport","no_sneak","no_steal",
                });
                    
    /* Smell is set like this... */
    smell = "Like a rose";
  /*move_object ("/players/thorm/objs/syllinor.c",this_object());*/
  }
}

init()
{
  ::init();
  add_action("main_oracle","oracle");
  add_action("or_players","players");
}

status main_oracle()
{
  write("How can I help you, Master?\n");
  
  return 1;
}

status or_players()
{
  int i;
  object *players;
  
  players = users();
  
  printf("%|78s\n","---------- Players seen by Oracle ----------");

  for (i=0;i<sizeof(players);i++)
  {
    printf("%25s%c",players[i]->query_real_name(),((i%3)==2)?'\n':' ');
  }
  if ((i%3) != 0) printf("\n");

  printf("%|78s\n","--------------------------------------------");

  return 1;
}
