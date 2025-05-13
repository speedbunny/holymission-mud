inherit "room/room";

reset(arg)
{
   ::reset(arg);
     
   if (arg) return;
 
   set_light(1);
   short_desc="move_blocked storeroom";
   long_desc= "This is the storeroom, where objects, moved by 'move_object_blocked'\n" +
               "will be stored.\n";
          
   dest_dir = ({ "players/patience/workroom.c","patience",
              });
             
}
  
init()
{
   ::init();
}

UpLoad( )
{
   return( 1 );
}
