
/* stoneskin */

inherit "/players/whisky/obj/std_shadow";

int i;
int done;

hit_player(dam,kind)
{
//	write("LAYERS left: "+i+"\n");
	
	if(done != 1)
	{
		write("INIT\n");
		i = 7 + random(4);
		done = 1;
	}

 if (i > 0 && (kind == 0 || kind == 7))
 {
      tell_object(me,"But your stoneskin protects you.\n");
		i--;
      return 0;
 }
 else if (i <= 0) 
     destruct(this_object());

	return dam;
}

   
void end_shadow()
{
   tell_object(me,"Your stoneskin wears off.\n");
   ::end_shadow();
}

int stone_shad() { return 1; }

