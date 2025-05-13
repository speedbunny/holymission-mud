inherit "room/room";
#define CRY "/players/kbl/objs/white_cr"
int crys;

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(0);
    short_desc = "Tight passage in the limestone";
    long_desc = "This place is very tight. The limestone formations have\n"+
                "tiny outcroppings of crystal on them.\n";
    dest_dir = ({
                 "/players/kbl/dungeon/dun5","east",
                 "/players/kbl/dungeon/dun13","west",
                 "/players/kbl/dungeon/dun20","down",
                });
    items = ({
              "outcroppings","White crystal of a very fine quality",
              "crystal","White crystal outcroppings of a very fine quality",
              "limestone","Large formations that extend up to the ceiling",
              "formations","Limestone formations that extend up to the ceiling",
             });
  }
  crys = 3;
}

init()
{
  ::init();
  add_action("break_it","break");
}

break_it(str)
{
  if(!str)
   return;
  switch(str)
  {
    case "crystal":
         if(crys)
         {
           tell_object(this_player(),"You break a crystal off the formation!\n")
;
           transfer(clone_object(CRY),this_player());
           crys-=1;
           return 1;
         }
         tell_object(this_player(),"There's no breakable crystal here now.\n");
         return 1;
  }
}
