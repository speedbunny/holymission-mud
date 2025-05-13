inherit "room/room";

object cat;
string food;

void reset (int arg)
{
  if (!cat)
  {
    cat = clone_object ("/players/muzmuz/monster/cat");
           move_object (cat,this_object());
  }
  if(!arg)
   {

     short_desc = "Cellar";
     long_desc =
  "This is the cellar of the house. It is warm and dry here.\n" +
  "It is quite dark here, but still enough light so you can see.\n" +
  "There is a cupboard at one side of the room and the stairs lead upwards.\n";

      items = ({
      "stairs","They lead upwards",
      "cupboard","@@is_here",
      "shadow","@@maybe_here",
      });

      dest_dir =({"/players/muzmuz/quest/hall2","upstairs",
                        });
   hidden_dir =({"/players/muzmuz/quest/hall2","up",
                       });
    set_light (1);
    enable_commands();
   }
}

string is_here()
{
   if (this_player()->food_shad() &&
      !find_object("/players/muzmuz/quest/guineapig"))
   {
      return ("A massive wooden cupboard standing on its wooden feet.\n"+
              "Under the cupboard you see a small shadow moving from\n"+
              "one edge to the other");
   }
   return "A massive wooden cupboard standing on its wooden feet";
}

string maybe_here() {

    if (this_player()->food_shad() &&
      !find_object("/players/muzmuz/quest/guineapig"))
            return "Looks small and furry";
    return "You do not see any shadows but your own";
}


void init()
{
  if (stringp(this_player()->query_food()))
      food = this_player()->query_food();
  ::init();
}


void catch_tell(string arg)
{
  object mob, pig, my_cat;
  string a, b;

     if (sscanf(arg,"%s drops %s",a,b)==2 && food &&
        (mob = present(food,this_object())) &&
         !find_object("/players/muzmuz/quest/guineapig"))
     {
        tell_room(this_object(),
        "A guineapig crawls out from under the cupboard and eats the "+food+
        ".\n");
        destruct(mob);
        if ( (my_cat = present("cat",this_object())) && living(my_cat))
        {
           tell_room(this_object(),
           "Suddenly the guineapig notices the cat and runs away.\n");
        }
        else
        {
          catch(move_object("/players/muzmuz/quest/guineapig",this_object()));
          pig = find_object("/players/muzmuz/quest/guineapig");
          pig->set_food(food);
          pig->set_friend(this_player());
        }
     }
}

