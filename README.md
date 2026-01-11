The files can't be ran in the Windows System. So you need to run it in WSL if in Windows.
If you have wsl installed open the folder and then press Ctrl + Shift + P and type "WSL: Reopen files in WSL"

If not alrady installed follow these steps:
1) wsl --install
2) After the installation you will be prompted to create a username and a password (NOTE: That the password will be hidden)
3) Then open Ubuntu and run  these commands:
4) sudo apt update
5) sudo apt install build-essential -y
6) Now Connect WSL to VS Code i.e  press Ctrl + Shift + P and type "WSL: Reopen files in WSL"
7) Now if you see "Your Project Folder Name' [WSL : Ubuntu]
8) Now Press Ctrl + Shift + X then you will be prompter to re-install the extensions into the WSL
9) After the extensions are installed now you can easily run your required file.
