class Result
{
	private:
	virtual void result_is(void)=0;
	public:
	virtual void what_happened(void)
	{this->result_is();}
};
