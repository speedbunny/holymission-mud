/*
	Apartment Editor
	by Kriton@Emerald MUD
*/

#include "apartment.h"

#define tmpfile()          sprintf("/tmp/apartment.%s", getuid(this_player()))

inherit OBJECT;

class apartment_rec ap;
string owner;
object room;
function f;

void menu();
void display(int);
void change_descriptions();
void change_mappings();
void change_properties();

void create()
{
  ::create();
  set_name("ap_edit");
  set_long("Dest me, please.");
  set_value(0);
  set_weight(0);
}

void setup(string str, class apartment_rec tmp, object r)
{
  owner = str;
  ap = tmp;
  room = r;
}

void init()
{
  ::init();
  if(this_player() && environment() != this_player())
  {
    remove();
    return;
  }
  menu();
}

void menu()
{
  write("\nEmerald MUD Inn Room Editor v1.0:\n"
  "  1) View Long/Shot Descriptions     2) Change Long/Short Descriptions\n"
  "  3) View Sounds/Smells/Items        4) Change Sounds/Smells/Items\n"
  "  5) View Properties                 6) Change Properties\n"
  "                X) Exit the Inn Room Editor\n");
  message("Nprompt", "Menu> ", this_player());
  input_to(function(string str)
  {
    switch(lower_case(str))
    {
      case "1":
        display(1);
        break;
      case "2":
        change_descriptions();
        break;
      case "3":
        display(2);
        break;
      case "4":
        change_mappings();
        break;
      case "5":
        display(3);
        break;
      case "6":
        change_properties();
        break;
      case "x":
        write("\nExiting.");
        if(objectp(room))
          room->load_apartment( ap );
        APARTMENT_D->save_apartment(owner, ap);
        remove();
        return;
      default:
        write("\nUnknown command.");
        menu();
    }
  });
}

void display(int mode)
{
  string tmp, *text;
  switch(mode)
  {
    case 1:
      write("\nShort Description:  "  +  ap->short + 
        "\n\nLong Description:\n" + ap->long);
      break;
    case 2:
      text = ({ "Items:" });
      foreach(tmp in keys(ap->items))
        text += ({ tmp + " : " + ap->items[tmp] });
      text += ({ "\nSmells:" });
      foreach(tmp in keys(ap->smells))
        text += ({ tmp + " : " + ap->smells[tmp] });
      text += ({ "\nSounds:" });
      foreach(tmp in keys(ap->sounds))
        text += ({ tmp + " : " + ap->sounds[tmp] });
      this_player()->more(text, "my_action", function()  
        {
          printf("\n[Press ENTER to Continue]: ");
          input_to("menu");
        });
      return;
    case 3:
      printf("Room is %s with %s.\n", (ap->indoors == 1 ? "indoors" :
      "outdoors"), evaluate(function(int light)  {
        switch(light)  {
          case -5: case -4: return "magical darkness";
          case -3: case -2: return "very dark lighing";
          case -1: case 0: return "normal darkness";
          case 1: case 2: return "normal light";
          case 3: return "very bright light";
          case 4: case 5: return "magical brightness";
        } // switch
      }, ap->light));
      break;
  }
  printf("\n[Press ENTER to Continue]: ");
  input_to("menu");
}

void change_descriptions()
{
  write("\nDescription Menu:\n"
  "  1) Change Short Description\n"
  "  2) Change Long Description\n"
  "  X) Exit to main menu\n");
  message("Nprompt", "Description Menu> ", this_player());
  input_to(function(string str)  {
    switch(lower_case(str))
    {
      case "1":
        printf("\nEnter a one line, short descriptiopn:\n\nShort: ");
        input_to(function(string str)  {
          if(strlen(str) == 0) str = "Emerald MUD Inn at Tear";
          write("\nDescription Changed.");
          ap->short = str;
          change_descriptions();
        });
        break;
      case "2":
        write("\nEnter a long description below:");
        rm(tmpfile());
        this_player()->edit(tmpfile(), "end_edit", this_object());
        break;
      case "x":
        return menu();
      default:
        change_descriptions();
    }
  });
}

void abort()
{
  rm(tmpfile());
  menu();
}

void end_edit()
{
  if(!file_exists(tmpfile())) return menu();
  ap->long = read_file(tmpfile());
  rm(tmpfile());
  menu();
}

void change_properties()
{
  write("\nProperties Menu:\n"
  "  1) Toggle Indoor/Outdoor flag (currently `"+
  (ap->indoors == 1 ? "indoors" : "outdoors") + "')\n"
  "  2) Change Room's Light Setting (currently `"+
  evaluate(f = function(int light)  {
        switch(light)  {
          case -5: case -4: return "magical darkness";
          case -3: case -2: return "very dark lighing";
          case -1: case 0: return "normal darkness";
          case 1: case 2: return "normal light";
          case 3: return "very bright light";
          case 4: case 5: return "magical brightness";
        } // switch
  }, ap->light) + "')\n"
  "  X) Exit to Main Menu\n");
  message("Nprompt", "Property Menu> ", this_player());
  input_to(function(string str)  {
    switch(str)
    {
      case "1":
        if(!(ap->indoors = !ap->indoors))
          write("\nThe room is now outdoors.");
        else
          write("\nThe room is now indoors.");
        change_properties();
        break;
      case "2":
        printf("\nEnter a valid light level (Magical Dark = -5 .. "
        "Magical Bright = 5)\n\nLight Level: ");
        input_to(function(string bob)  {
          int x;
          if(!(x = atoi(bob)) && bob != "0")
          {
            write("\nYou may only type in numbers.");
            return change_properties();
          }
          if(x < -5 || x > 5)
          {
            write("\nThe number must be between -5 and 5.");
            return change_properties();
          }
          ap->light = x;
          printf("\nLight level now set to `%s'\n", evaluate(f, ap->light));
          change_properties();
        });
        break;
      case "x":
        return menu();
      default:
        change_properties();
    }
  }); /* input_to */
}

void change_mappings()
{
  write("\nSenses Menu:\n"
  "  1) Add Item                2) Remove Item\n"
  "  3) Add Smell               4) Remove Smell\n"
  "  5) Add Sound               6) Remove Sound\n"
  "  X) Exit to Main Menu\n");
  message("Nprompt", "Senses Menu> ", this_player());
  input_to(function(string str)
  {
    switch(str)  {
      case "1":
        printf("\nAdding an item.  Enter the item's identifier.\n\nItem ID: ");
        input_to(function(string bob)
        {
          if(strlen(bob = replace_string(bob, " ", "")) == 0)
            return change_mappings();
          write("\nPlease describe `"+bob+"' below:\n");
          message("Nprompt", "Description: ", this_player());
          input_to(function(string x, string y)
          {
            if(strlen(x) == 0) return change_mappings();
            ap->items[y] = x;
            write("\nItem `"+y+"' added.");
            return change_mappings();
          }, bob);
        });
        break;
      case "2":
        printf("\nDelete which item (`=' will list items)\n\nDelete> ");
        input_to(function(string str)  {
          if(strlen(str) == 0)
            return change_mappings();
          if(str == "=")
          {
            if(sizeof(ap->items) > 0)
              write("\nThe following items are defined:\n"
                + implode(keys(ap->items), ", "));
              else write("\nThere are NO items defined.");
            change_mappings();
            return;
          }
          if(undefinedp(ap->items[str]))
          {
            write("\nNo such item defined.");
            return change_mappings();
          }
          map_delete(ap->items, str);
          write("Item `"+str+"' removed.");
          change_mappings();
        });
        break;
      case "3":
        printf("\nAdding an smell.  Enter the smell's identifier.\n"
          "\nSmell ID (`default' if you want it in room desc): ");
        input_to(function(string bob)
        {
          if(strlen(bob = replace_string(bob, " ", "")) == 0)
            return change_mappings();
          write("\nPlease describe the smell of `"+bob+"' below:\n");
          message("Nprompt", "Description: ", this_player());
          input_to(function(string x, string y)
          {
            if(strlen(x) == 0) return change_mappings();
            ap->smells[y] = x;
            write("\nSmell `"+y+"' added.");
            return change_mappings();
          }, bob);
        });
        break;
      case "4":
        printf("\nDelete which smell (`=' will list items)\n\nDelete> ");
        input_to(function(string str)  {
          if(strlen(str) == 0)
            return change_mappings();
          if(str == "=")
          {
            if(sizeof(ap->smells) > 0)
              write("\nThe following smells are defined:\n"
                + implode(keys(ap->smells), ", "));
              else write("\nThere are NO smells defined.");
            change_mappings();
            return;
          }
          if(undefinedp(ap->smells[str]))
          {
            write("\nNo such smell defined.");
            return change_mappings();
          }
          map_delete(ap->smells, str);
          write("Smell `"+str+"' removed.");
          change_mappings();
        });
        break;
      case "5":
        printf("\nAdding a sound.  Enter the sounds's identifier.\n"
          "\nSound ID (`default' if you want it in room desc): ");
        input_to(function(string bob)
        {
          if(strlen(bob = replace_string(bob, " ", "")) == 0)
            return change_mappings();
          write("\nPlease describe the sound of `"+bob+"' below:\n");
          message("Nprompt", "Description: ", this_player());
          input_to(function(string x, string y)
          {
            if(strlen(x) == 0) return change_mappings();
            ap->sounds[y] = x;
            write("\nSound `"+y+"' added.");
            return change_mappings();
          }, bob);
        });
        break;
      case "6":
        printf("\nDelete which sound (`=' will list items)\n\nDelete> ");
        input_to(function(string str)  {
          if(strlen(str) == 0)
            return change_mappings();
          if(str == "=")
          {
            if(sizeof(ap->sounds) > 0)
              write("\nThe following sounds are defined:\n"
                + implode(keys(ap->sounds), ", "));
              else write("\nThere are NO sounds defined.");
            change_mappings();
            return;
          }
          if(undefinedp(ap->sounds[str]))
          {
            write("\nNo such sound defined.");
            return change_mappings();
          }
          map_delete(ap->sounds, str);
          write("Sound `"+str+"' removed.");
          change_mappings();
        });
        break;
      case "x":
        return menu();
    } /* main switch */
  });
}
