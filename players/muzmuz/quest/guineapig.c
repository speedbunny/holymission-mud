

/* guineapig */

#define env environment

inherit "/obj/monster";

object friend;
string what_food;
int counter;
int get_quest;

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
        get_quest = 1;
        counter = 12; 
        what_food = "bananas";
        set_name("guineapig");
        set_alt_name("pig");
        set_short(query_name());
        set_long(
        "A cute, scared guineapig. It seems to be hungry.\n"+
        "If you are nice and feed it, maybe you can earn\n"+
        "its trust.\n");
         set_level(1);
         enable_commands();
         set_heart_beat(1);
      }
}

mixed set_friend(object f) 
{
     if (objectp(f))
     {
        friend = f;
        return friend;
     }
    return 0;
}

string set_food(string f)
{
        return (what_food = f);
}

void heart_beat()
{
  object girl, book;

     if (girl = present("questgirl",env()))
     {
        if (get_quest)
        {
            tell_room(env(),
            "Guineapig oinks happily and runs up to the girl.\n");
            get_quest = 0;
        }
        friend->set_quest("guineapig");
        girl->is_happy();
        if (book = present("quest_book",friend))
            destruct(book);
        set_friend(girl);
     }
     else if (objectp(friend) && living(friend) && present(what_food,friend)) 
     {
         counter = 12;
         if (env() != env(friend))
         {
            tell_room(env(friend),
            "Guineapig comes in searching for more "+what_food+".\n");
            tell_room(env(),
            "Guineapig leaves searching "+what_food+".\n");
            move_object(this_object(),env(friend));
         }
      }
    counter--;
    if (counter < 0)
    {
        if (!girl)
        {
         tell_room(env(),
         "The guineapig leaves suddenly.\n");
        }
        else
        {
         tell_room(env(),
         "The guineapig jumps into the girl's arms.\n");
        }
         destruct(this_object());
    }
} 
        
      
void catch_tell(string arg)
{
    string a,b;
    object mob;

    if (what_food && sscanf(arg,"%s drops %s",a,b)==2)
    {
        if (mob = present(what_food,env()))
        {
          tell_room(env(),
          "The guineapig happily eats the "+what_food+".\n");
          destruct(mob);
        }
    }
}

             



