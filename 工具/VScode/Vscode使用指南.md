# VScode如何配置`setting.json`
1. 快捷键`ctrl + shift + p`打开命令面板，输入`settings.json`,选择`Open Settings(Json)`。
2. 其中常用配置有：
   ```json
    {
        "files.autoSave": "onFocusChange",  //窗口失焦自动保存
        "editor.fontFamily": "JetBrains Mono, Consolas, 'Courier New',monospace",   //字体设置
        "terminal.integrated.shell.windows": "D:\\Git\\bin\\bash.exe",  //设置终端，注意双斜线转义
    }
   ```