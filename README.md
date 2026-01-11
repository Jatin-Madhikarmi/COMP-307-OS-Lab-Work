Project Setup Guide (WSL for Windows)
This project is designed to run in a Linux environment. Windows users should use WSL (Windows Subsystem for Linux) to ensure all dependencies work correctly.

1. Install WSL
If you don't have WSL installed, open PowerShell or Command Prompt as an Administrator and run:

Bash

wsl --install
Note: After installation, restart your computer. You will be prompted to create a username and password. (The password will be hidden while you type).

2. Configure Ubuntu
Open the Ubuntu terminal and run the following commands to update your system and install build tools:

Bash

sudo apt update && sudo apt install build-essential -y
3. Open Project in WSL
To run this project, you must reopen your files inside the Linux environment using VS Code:

Open your project folder in VS Code.

Press Ctrl + Shift + P to open the Command Palette.

Type and select: WSL: Reopen Folder in WSL.

Verify: The bottom-left corner of VS Code should now say WSL: Ubuntu.

4. Install Extensions in WSL
Once connected to WSL, you must enable your extensions for the Linux environment:

Press Ctrl + Shift + X to open the Extensions menu.

Look for the message "Install in WSL: Ubuntu" for your required extensions.

Click the button to re-install them.

5. Run the Project
Now that your environment is set up, you can run the required files through the VS Code terminal.

Pro-Tip for READMEs:
If you want to make this even better, you can add a "Troubleshooting" section at the bottom. Would you like me to include some common fixes for WSL connection issues?
