class Cryptocurrency_Bag_base extends Cryptocurrency_base
{
	override bool CanReceiveItemIntoCargo (EntityAI item)
    {
        if ( item.IsKindOf("Cryptocurrency_base"))
        {
            return true;
        };
        return false;
    }
}
