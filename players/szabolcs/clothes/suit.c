inherit "/obj/armour";

reset(arg)
{
   ::reset(arg);
     if (arg) return;
        set_id("dress");
     set_alias( ({"suit","wedding suit"})  );
     set_short("wedding dress");
      set_long("This is a beatiful dark suit , made of\n"+
          "silk.It contains a white handcerchief with F.SZ.\n"+
          "monogram.");
      set_type("cloak");
set_ac(1);
      set_weight(1);
      set_value(4000);
      }

   void init()
{
   ::init();
}
