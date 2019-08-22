#### VS code 设置

一、`tab`一律用`4`个空格不要检测到第一个是`tab`，就后面都用`tab`，这样会覆盖默认设置。

-  `tabSize` 查找,取消 `tab size/spaces automatically detected when a file is opened.`

二、显示空格和`tab`
- `renderControlCharacters` 查找,选中勾选框,即可显示`tab`.
- `renderWhitespace` 查找,选择`all`,即可显示空格.


三、或者`json`脚本里面添加：
```json
"editor.detectIndentation": false,      //不检测到第一个是tab后面都用tab
"editor.renderControlCharacters": true, //显示制表符是→
"editor.renderWhitespace": "all",       //显示4个空格是....
"editor.tabSize": 4,                    //tab设置为4个空格
```