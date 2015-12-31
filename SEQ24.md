#SEQ24 - Midi Sequencer

[1] What & Why
[2] Who 
[3] Interface
[4] Contact / Bugs / Ideas
[5] License


##What & Why

Seq24 is a real-time midi sequencer. It was created to 
provide a very simple interface for editing and playing 
midi 'loops'. After searching for a software based 
sequencer that would provide the functionality needed for 
a live performance, there was little found in the 
software realm. I set out to create a very minimal sequencer 
that excludes the bloated features of the large software 
sequencers, and includes a small subset of features that 
I have found usable in performing. 


##Who 

Written by Rob C. Buse.  I wrote this program to fill a
hole.  I figure it would be a waste if I was the only one
using it.  So, I released it under the GPL.


##Interface

The program is basically a loop playing machine with a 
simple interface.


###Main Window

#####File. 

        The File menu is used to save and load standard 
	MIDI files.  It should be able to handle any 
	Format 1 standard files, Any other sequencer 
	should be capable of exporting.  

#####Options

	Used to configure what bus midi clock gets dumped to.

#####Help.
	
	Shows the About box.
	
#####Boxes

	Each box represents a loop. By right clicking 
	on an empty box you bring up a menu to create
	a new loop, or edit a existing one.

	Left clicking on a box will change its state
	from muted (white) to playing (black) when
	the sequencer is running.

	By clicking and holding the left button on a sequence,
	you can drag it to a new location on the grid.

        Right Clicking will bring up a menu of available options
        for the sequence.  Here you can select the midi bus/channel.
        You can also clear all performance data (on/off) see section
        [3d] for more info.

#####'Screen Sets'

	You only see 32 loops in the main window.  This
	is a screen set.  You can switch between sets
	by using the '[' and ']' keys on your keyboard or
	the spin widget labeled set.  
	There are a total of 32 sets, for a total of 
	1024 loops. 

#####BPM

	The ; and ' keys will increase/decrease tempo as
	will the bpm spinner.	

#####Muting and Unmuting Tracks.

Left clicking on a Tracks will toggle its playing status.  Hitting its assigned keyboard key will also toggle its status.  Below is the grid thats 	mapped to the loops on the screen set.

	[1    ][2    ][3    ][4    ][5    ][6    ][7    ][8    ]
	[q    ][w    ][e    ][r    ][t    ][y    ][u    ][i    ]
	[a    ][s    ][d    ][f    ][g    ][h    ][j    ][k    ]
	[z    ][x    ][c    ][v    ][b    ][n    ][m    ][,    ]

#####Mute/Unmute patterns (Groups)

You can toggle the playing status of up to 32 previously 
defined mute/unmute patterns (groups) in the active screen 
set, similar to hardware sequencers. 
	This is done either by one of the 'group toggle' keys 
	or by a MIDI controller, both assigned in the .seq24rc file. 
	A Mute/Unmute pattern (group) is stored by holding a 
	'group learn' key while pressing the corresponding 
	'group toggle' key. 
	There are also keys assigned to turn on/off the group 
	functionality.
    
#####Replace

	Holding down 'Left Ctrl' while selecting a sequence 
	will mute all other sequences and turn on the selected
	sequences.

        * Restore

	Holding 'Alt' will save the state of playing sequences
	and restore them when 'Alt' is lifted.

	Holding 'Left Ctrl' and 'Alt' at the same time will enable
	you to flip over to new sequences briefly and then
	flip right back upon lifting 'Alt'.

        * Queue

	Holding 'Right Ctrl' will queue a on/off toggle for a 
	sequence when the loop ends. Queue also works for mute/unmute 
	patterns (groups), in this case every sequence will toggle 
	its status after its individual loop end. 

        * keep queue

	Pressing the 'keep queue' key assigned in the .seq24rc file 
	activates permanent queue mode until you use the temporary 
	Queue function again pressing 'Right Ctrl'. 


###Options Window

This window allows us to select which sequence gets midi
        clock, and which incoming midi events control the sequencer.


###Edit Window

Right clicking on the main window then selecting
	New/Edit will bring up the edit window.	

The top bar of the sequence editor lets you 
	change the name of the sequence, the time 
        signature of the piece, and how long the loop
        is.

Snap selects where the notes will be drawn. 
Note Length determines what size they will be.  
Scale 
        is the relation between midi ticks and pixels. 
        1:4 = 4 ticks per pixel.  
The Bus button selects
        which ALSA device to use, and which midi channel.          

The 3rd line contains the Undo button, which will roll
        back any changes to the sequence from this session.
        You can select which Scale and Key the piece is in
        and it will grey out those keys on the roll not in 
        the key.  You can select a sequence to draw on the 
        background to help with writing corresponding parts.

Holding the mouse over any button for a short period
	will let you view what it does.

While the sequencer is playing, you can mute/unmute
	the sequence by toggling the [Play] button.  The 
	[Thru] button will relay any ALSA midi input
	to the sequences Bus and midi channel.  [Record] 
	will capture and ALSA midi input and save it in the
	sequence.

On both the grid window and the event window, HOLDING
	down the right mouse button will change your cursor
	to a pencil and put you in 'draw' mode.  Then while
        still HOLDING the right mouse button, click the left
        mouse button to insert new notes.  Many people find 
        this combination strange at first, but once you get
        used to it, it becomes a very fast method of note
        manipulation.

Pressing  the middle mouse button will let you change 
	the length of the note. 

The left mouse button lets you select multiple events 
        which can then be clicked and moved, cut (Ctrl-X), 
        copy (Ctrl-C), or pasted (Ctrl-V).  When the notes are 
        selected, you can delete them with the Delete key.

Right clicking on the event strip ( directly under
	the paino roll grid ) will allow you to add/select/move 
	midi events (not note on/off messages) somewhat like the 
	piano grid.

The data editor ( directly under the event strip ) is used 
	to change note velocities, channel pressure, control codes,
	patch select, etc.  Just click + drag the mouse across 
	the window to draw a line.  The values will match that line.
        Any events that are selected in the paino roll or event
        strip can have their values modified with the mouse 
        wheel.

The [Event] button allows you to select which type of data
	the event strip and data editor are currently displaying.


###Performance Edit (aka Song Editor)

Right Click on the Roll to enter draw mode, gray boxes
	represent when the track is on.  Right and left click to
	drop the [R] and [L] anchors on the bar indicator.  Use
	the collapse and expand button to modify events.  Middle
	click on the bar indicator to drop a new start position.
	You can only change the start position when the performace
	is not playing.


###.seq24rc File 

After you run seq24 for the first time, it will generate 
        a .seq24rc file in your home directory.

It contains the the data for remote midi control, keyboard
        control, and midi clock.

#####[midi-control]

For each sequence, we can set up midi events to turn a 
	sequence on, off, or toggle it.  We see the following
	lines in the [midi-control] section:

        0  [0 0 0 0 0 0]   [0 0 0 0 0 0]   [0 0 0 0 0 0]            
        1  [0 0 0 0 0 0]   [0 0 0 0 0 0]   [0 0 0 0 0 0]          
        2  [0 0 0 0 0 0]   [0 0 0 0 0 0]   [0 0 0 0 0 0]   
        ...

The first number is the sequence in the main window.  Each set 
        of brackets corresponds to a midi filter.  If the incoming midi 
        event matches the filter, it will either [toggle],[on],or[off] 
   	the sequence  respectivaly.

        The layout of each filter inside the bracket is as follows:

        [(on/off) (inverse) (midi status byte (channel ignored)) 
                                     (data1) (data2 min) (data2 max)]

	If the on/off is set to 1, it will match the incoming midi 
        to the pattern and perfrom the 	action (on/off/toggle) 
        if the data falls in the range specified.  All values 
	are in decimal.

	The last three is the range of data that will match.

	The following is an example of responding to note on events, 
        note 0, with any velocity to turn the sequence on, and note 
        off events, note 0, and any velocity to turn the sequence off.

	  Toggle                 On                         Off
        1 [0 0 0 0 0 0]         [1 0  144 0 0 127]          [1 0 128 0 0 127]

	the inverse field will make the sequence perform the opposite 
        action (off for on, on for off) if the data falls outside the 
        specified range.  This is cool because you can map several 
        sequences to a knob or fader.

	The following example would map a row of sequences to one knob 
        sending out changes for Control Code 1:

	Toggle            On                    Off
        
        0  [0 0 0 0 0 0]  [1 1 176 1   0   15]  [0 0 0 0 0 0]
        1  [0 0 0 0 0 0]  [1 1 176 1  16   31]  [0 0 0 0 0 0]
        2  [0 0 0 0 0 0]  [1 1 176 1  32   47]  [0 0 0 0 0 0]
        3  [0 0 0 0 0 0]  [1 1 176 1  48   63]  [0 0 0 0 0 0]
        4  [0 0 0 0 0 0]  [1 1 176 1  64   79]  [0 0 0 0 0 0]
        5  [0 0 0 0 0 0]  [1 1 176 1  80   95]  [0 0 0 0 0 0]
        6  [0 0 0 0 0 0]  [1 1 176 1  96  111]  [0 0 0 0 0 0]
        7  [0 0 0 0 0 0]  [1 1 176 1 112  127]  [0 0 0 0 0 0]
        # mute in group
       
        This section controls 32 groups of mutes in the same way as 
	defined for [midi-control]. A group is a set of sequences 
	that can toggle their playing state together.
        Every group contains all 32 sequences in the active screen 
	set (see after).
       

     
        [mute-group]

        Here there are the definitions of the state of the 32 sequences
        in the playing screen set when a group is selected.
        group [state of the first 8 sequences] [second 8] [third 8] [fourth 8]

        After the list of sequences and their midi events, you can 
        set seq24 to handle midi events and change the following: 


        * [midi-clock]

        The midi clock fields will contain the clocking state from the last 
        time seq24 was run.  Turn off clock with a 0, or on with a 1.


        * [keyboard-control]      
        
        The keyboard control is a dump of the keys that seq24 
        recognises and its corresponding sequence number.
	Note that the first number corresponds to the number of sequences in
	the active screen set.

        * [keyboard-group]

        Same as keyboard-control, but to control groups.

   	#bpm up and down					
	-> keys to control bpm
	#screen set up and down					
	-> keys for changing the active screenset
	#group functionality on, group functionality off, group learn
	-> note that the group learn key is a modifier key to be held while 
	   pressing a group toggle key
        #replace, queue, snapshot_1, snapshot_2, keep queue
	-> These are the other modifier keys explained in section 3a.
	
   
     *NOTES*: 
	To see the required key codes when pressed, run seq24 with --show_keys.

	Seq24 will overwrite the .seq24rc file on quit. You should therefore
	quit seq24 before doing modifications to the .seq24rc file.

	Some keys should not be assigned to control sequences in seq24 as they
	are already assigned in the seq24 menu (with ctrl). 
	

[3f] JACK Transport

        In order to run seq24 with JACK Tranport Sync, you need 
        to enable it at the command line with the following flags:

        --jack_transport : seq24 will sync to JACK transport 
                           if the JACK server is available.
        
        --jack_master : seq24 will try to be JACK master
        
        --jack_master_cond : The attempt to be JACK master will 
                             fail if there is already a master,
                             otherwise it will just take over.

        --jack_start_mode <x> : When seq24 is synced to JACK,  
                                The playback command comes 
                                from the JACK server.  seq24 will 
                                play in performance mode
                                by default (section [3d]).  
                                If you want live mode, set 
                                --jack_start_mode 0.

        It is best to run seq24 with another master like ardour.  You
        can not change the BPM of seq24 while rolling in JACK sync mode.


-----------------------------------------------------------

##Contact

	If you have Ideas about seq24 or a bug report,
please email seq24@filter24.org.  If its a bug report,
please add [BUG] to the subject.

-----------------------------------------------------------

##License

Released under the Terms of the GPL.  See the COPYING file
for a full readout.
