class Cryptocurrency_Bag extends Container_Base
{
	override bool IsContainer()
	{
		return true;
	}
	
	override bool CanPutInCargo( EntityAI parent )
	{
		if( !super.CanPutInCargo(parent) ) {return false;}	
		if ( parent && (parent.IsKindOf("WaterproofBag_ColorBase")) )
		{
			return false;
		}
		
		return true;
	}

	override bool CanReceiveItemIntoCargo (EntityAI item)
    {
        if ( item.IsKindOf("Cryptocurrency_base"))
        {
            return true;
        };
        return false;
    }
}
