
inherit "/obj/std_shadow";

string food;

int food_shad()
{
    return 1;
}

object food_object()
{
    return this_object();
}

string set_food(string f)
{
      return (food = f);
}

string query_food()
{
      return food;
}

     
