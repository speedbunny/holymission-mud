
inherit "/obj/armour";

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
	set_name("Ranma's Army jacket");
	set_alias("jacket");
        set_short("Ranma's Army Jacket");
        set_long(
	"An enchanted Nihonese Army jacket, Ranma wears this as his"+
	" body armour.\n");
	set_type("cloak");
    set_ac(1);
	set_weight(1);
	set_value(4000);
     }
}

