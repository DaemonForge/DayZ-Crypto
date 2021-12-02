modded class MissionBase
{
    override UIScriptedMenu CreateScriptedMenu(int id) {
        UIScriptedMenu menu = NULL;
        menu = super.CreateScriptedMenu(id);
        if (!menu) {
            switch (id) {
                case CRYPTO_MENU:
                    menu = new CryptoTraderMenu;
                    break;
            }
            if (menu) {
                menu.SetID(id);
            }
        }
        return menu;
    }
	
}