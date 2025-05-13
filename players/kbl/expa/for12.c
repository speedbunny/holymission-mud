inherit "/players/kbl/objs/gfor";
#define FOX "/players/kbl/objs/fox"
#define BAT "/players/kbl/objs/bat"

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    dest_dir = ({
                 "/players/kbl/expa/for13","north",
                 "/players/kbl/expa/for4","south",
                });
  }
}

init()
{
  ::init();
  event();
}

event()
{
  if(random(60) > 55)
   transfer(clone_object(FOX),this_object());
  if(random(60) > 57)
   transfer(clone_object(BAT),this_object());
}
