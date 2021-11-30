class CyptoMarketHandler extends Managed {
	
	static int FAILED = -1;
	static int WAITINGFORFIRST = 0;
	static int PENDING = 1;
	static int UPDATED = 2;
	
	protected autoptr UApiCryptoResults m_Cache;
	protected int m_LastCacheStatus = WAITINGFORFIRST;
	protected int m_LastCacheTime = 0;
	protected bool m_CacheIsActive = false;
	
	void CyptoMarketHandler(){
		
	}
	
	
	
	void CBUpdateCache(int cid, int status, string id, UApiCryptoResults data){
		if (status == UAPI_SUCCESS){
			Class.CastTo(m_Cache, data);
			m_LastCacheStatus = UPDATED;
			m_LastCacheTime = GetGame().GetTime();
		} else {
			m_LastCacheStatus = FAILED;
		}
	}
}