inherit "room/room";

string hole;

reset( arg )
{
   ::reset( arg );

   if ( arg )
      return;

   short_desc = "Flee fool !!!";

   long_desc = 
        "You are in a cave inside the volcano of Ezo. The walls here\n" +
        "are of dark, colded lava. Everywhere at the wall are scratches\n" +
        "of mighty paws and the walls are red of blood. You feel very uneasy!!!"
        + "\n";

   items = ({ "walls", "They are pitch black and full with blood@@c_hole@@",
              "wall", "It is pitch black and full with blood@@c_hole@@",
              "scratches", "The scratches cut deep into the lava",
              "scratch", "The scratch cuts deep into the lava",
              "lava", "It is pitch black and full of blood",
              "blood", "It is group 0, Rh pos D, kell +\n" +
                       "Isn't this the one, Patience has ?",
              "hole", "@@l_hole@@",
           });

   property = "no_teleport";
}

init()
{
   ::init();
}

query_hole()
{
   if ( !hole || !stringp( hole ) || !strlen( hole ) )
      return;

   return( hole );
}

l_hole( )
{
   if ( query_hole() )
      return( "It is pitch black inside" );
   return( "Do you see a hole here ? hmmm.." );
}

c_hole()
{
   if ( query_hole() )
      return( "Near the floor is a small hole in the wall.\n" );
   return( "" );
}

move(str) {
    int i;
    string *dirs;

    if (!str) str=query_verb();
    dirs=dest_dir;
    if(hidden_dir) { if(dirs) dirs+=hidden_dir; else dirs=hidden_dir; }

    if ((i = member_array(str, dirs)) != -1) {
      if ( present( "kojin", this_object() ) && i != 1 ) {
         write( "The kojin hinders you to leave " + dirs[i] + ".\n" );
         return( 1 );
      }
      if (dirs[i-1]=="") return 0;
      this_player()->move_player(dirs[i] + "#" + dirs[i-1]);
      return 1;
    }
}
