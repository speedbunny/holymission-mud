
inherit "/obj/key";

void reset(int tick)
{
     ::reset(tick);
     if (!tick)
     {
        set_key_data("wooden key","4711");
        set_code("4711");
     }
}

