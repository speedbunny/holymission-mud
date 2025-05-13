
// changed to room/room : whisky

inherit "/room/room";

void reset(int tick)
{
     ::reset(tick);
     if (!tick)
     {
         set_light(1);
         dest_dir = ({
                    "players/padrone/maze/moses_office", "north",
         });
	 short_desc = "Moses Schoenfinkel's garden",
         long_desc =
	 "This is a small garden outside the office of Moses Schoenfinkel.\n" +
	 "Well-kept flowers and small bushes make this garden a beautiful place.\n" +
	 "A high thorn hedge surrounds the garden. Strangely enough, there are\n" +
	 "no openings in the hedge, making the door back into Moses' office\n" +
	 "the only way to leave the garden.\n";
     }
}

