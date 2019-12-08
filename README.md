# LumberjackGame

This Lumberjack game is a clone of the Timber game, which is based on ideas and concepts from LinkedIn's course "C++ Game Programming 1"
and "Beginning C++ Game Programming" both by John Horton.

- You must have installed SFML 2.4.0 32 bit version (SFML-2.4.0-windows-vc14-32)
- The installation package is provided with this project, look for the "SFML-2.4.0-windows-vc14-32-bit.zip" file
- The installation folder must be: "C:\Program Files (x86)\SFML"


Building the game with Visual Studio (2019)
------------
- With the Solution open, right-click on Timber, and then click on Properties
- On Configuration Drowndown menu select 'All configurations'
- Selecting 'C/C++' -> 'General' -> on 'Additional Include Directories' field add the following directory 'C:\Program Files (x86)\SFML\include\'
	<p>&nbsp;&nbsp;&nbsp;&nbsp;*Note: If 'C:\Program Files (x86)\SFML' is not your SFML installation you should adjust it accordingly to your settings.</p>

- Selecting 'Linker' -> 'General' -> on 'Additional Include Directories' field add the following directory 'C:\Program Files (x86)\SFML\lib'
	<p>&nbsp;&nbsp;&nbsp;&nbsp;*Note: If 'C:\Program Files (x86)\SFML' is not your SFML installation you should adjust it accordingly to your settings.</p>

- On Configuration Drowndown menu select 'Debug'
- Then go to 'Linker' -> 'General' -> 'Input' -> on 'Aditional Dependencies' field append the following string 
	<p>&nbsp;&nbsp;&nbsp;&nbsp;'sfml-graphics-d.lib;sfml-window-d.lib;sfml-system-d.lib;sfml-system-d.lib;sfml-network-d.lib;sfml-audio-d.lib;'</p>
	<p>&nbsp;&nbsp;&nbsp;&nbsp;The working copy ideally should look like this:</p>
	<p>&nbsp;&nbsp;&nbsp;&nbsp;'sfml-graphics-d.lib;sfml-window-d.lib;sfml-system-d.lib;sfml-system-d.lib;sfml-network-d.lib;sfml-audio-d.lib;kernel32.lib;user32.lib;gdi32.lib;winspool.lib;comdlg32.lib;advapi32.lib;shell32.lib;ole32.lib;oleaut32.lib;uuid.lib;odbc32.lib;odbccp32.lib;%(AdditionalDependencies)'</p>

- On Configuration Drowndown menu select 'Release'
- Then go to 'Linker' -> 'General' -> 'Input' -> on 'Aditional Dependencies' field append the following string 
	<p>&nbsp;&nbsp;&nbsp;&nbsp;'sfml-graphics.lib;sfml-window.lib;sfml-system.lib;sfml-network.lib;sfml-audio.lib;'</p>
	<p>&nbsp;&nbsp;&nbsp;&nbsp;The working copy ideally should look like this:</p>
	<p>&nbsp;&nbsp;&nbsp;&nbsp;'sfml-graphics.lib;sfml-window.lib;sfml-system.lib;sfml-network.lib;sfml-audio.lib;kernel32.lib;user32.lib;gdi32.lib;winspool.lib;comdlg32.lib;advapi32.lib;shell32.lib;ole32.lib;oleaut32.lib;uuid.lib;odbc32.lib;odbccp32.lib;%(AdditionalDependencies)'</p>




Commands
------------
- "Esc" exit the game
- "Enter" start the game
- "Right arrow" and "Left arrow" perform an action
