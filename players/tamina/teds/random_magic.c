/* ------------------------------------------------------------------------- 
             Created by Ted                                          
   This will create some random magic and put it on the monster       
   from which this is called from......simply put this line in:        
                                                                        
 "/players/tamina/teds/random_magic"->make_item(monster_obj, level); 
                                                                  
   where monster_ob is the monster currently being created and the 
   level is the level of the monster. For example:
                                                
  guard = clone_object("obj/monster");            
  guard->set_name("Treasury Guard"); 
  guard->set_level(14);                // Max = 30
  ...
  etc
  ...
  "/players/tamina/teds/random_magic"->make_item(guard, 14); 

  -=- Updated by Elemental Tamina  28-09-94

  -=- Completely re-written        16-05-95
                                                               
 ------------------------------------------------------------------------- */

#define CLO clone_object

int make_item(object ob, int level) 
{
  object item;

  switch (level + random(51))
  {
    case 0 .. 10:
      item = CLO("/players/tamina/teds/items/bag_of_holding");
      transfer(item, ob);
    break;
    case 11 .. 20:
      item = CLO("/players/tamina/teds/wands/air");
      transfer(item, ob);
    break;
    case 21 .. 22:
      item = CLO("/players/tamina/teds/items/identify");
      transfer(item, ob);
    break;
    case 24 .. 30:
      item = CLO("/players/tamina/teds/wands/fire");
      transfer(item, ob);
    break;
    case 31 .. 35:
      item = CLO("/players/tamina/teds/items/crystal_ball");
      transfer(item, ob);
    break;
    case 36 .. 40:
      item = CLO("/players/tamina/teds/wands/fear");
      transfer(item, ob);
    break;
    case 41 .. 44:
      item = CLO("/players/tamina/teds/wands/air");
      transfer(item, ob);
    break;
    case 45 .. 49:
      item = CLO("/players/tamina/teds/wands/air");
//      item = CLO("/players/tamina/teds/wands/stars");
      transfer(item, ob);
    break;
    case 50 .. 51:
      item = CLO("/players/tamina/teds/items/identify");
      transfer(item, ob);
    break;
    case 54 .. 56:
      item = CLO("/players/tamina/teds/wands/cold");
      transfer(item, ob);
    break;
    case 57 .. 59:
      item = CLO("/players/tamina/teds/items/raise_rod");
      transfer(item, ob);
    break;
    case 60 .. 62:
      item = CLO("/players/tamina/teds/wands/fire");
      transfer(item, ob);
    break;
    case 63 .. 64:
      item = CLO("/players/tamina/teds/items/identify");
      transfer(item, ob);
    break;
    case 66 .. 68:
      item = CLO("/players/tamina/teds/wands/cold");
      transfer(item, ob);
    break;
    case 69 .. 71:
      item = CLO("/players/tamina/teds/items/raise_rod");
      transfer(item, ob);
    break;
    case 72:
      item = CLO("/players/tamina/teds/wands/fear");
      transfer(item, ob);
    break;
    case 73:
      item = CLO("/players/tamina/teds/wands/lightning");
      transfer(item, ob);
    break;
    case 74:
      item = CLO("/players/tamina/teds/items/healpotion");
      transfer(item, ob);
    break;
    case 75:
      item = CLO("/players/tamina/teds/items/crystal_ball");
      transfer(item, ob);
    break;
    case 76:
      item = CLO("/players/tamina/teds/items/cure_staff");
      transfer(item, ob);
    break;
    case 77:
      item = CLO("/players/tamina/teds/wands/cold");
      transfer(item, ob);
    break;
    case 78:
      item = CLO("/players/tamina/teds/wands/plasma");
      transfer(item, ob);
    break;
    case 79:
      item = CLO("/players/tamina/teds/items/healpotion");
      transfer(item, ob);
    break;
    case 80:
      item = CLO("/players/tamina/teds/wands/lightning");
      transfer(item, ob);
    break;
    default:
      item = CLO("/players/tamina/teds/wands/plasma");
      transfer(item, ob);
    break;
  }
  return 1;
}
