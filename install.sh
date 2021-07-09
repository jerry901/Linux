sudo apt update 
sudo apt install -y curl 
sudo apt install -y build-essential
sudo apt install -y zsh
sudo apt install -y wget
sudo apt install -y gnome-shell-extensions
sudo apt install -y tilda
sudo apt install -y neovim


curl -sL https://deb.nodesource.com/setup_14.x | sudo bash -
sudo apt -y install nodejs

sudo apt-add-repository universe  
sudo apt install gnome-tweak-tool
sudo apt-get install -y dconf-editor 


mkdir -p "$HOME/.pure"
git clone https://github.com/sindresorhus/pure.git "$HOME/.pure"

(mkdir $HOME/dotfiles; git clone https://github.com/jerry901/dotfiles.git "$HOME/dotfiles"; cd $HOME/dotfiles; git checkout linux; cp $HOME/dotfiles/shell/.zshrc $HOME)

git clone https://github.com/zsh-users/zsh-syntax-highlighting.git ${ZSH_CUSTOM:-~/.oh-my-zsh/custom}/plugins/zsh-syntax-highlighting

git clone --depth 1 https://github.com/junegunn/fzf.git ~/.fzf
~/.fzf/install

sh -c "$(curl -fsSL https://raw.githubusercontent.com/robbyrussell/oh-my-zsh/master/tools/install.sh)"

