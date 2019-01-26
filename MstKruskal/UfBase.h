class unionFind
{ //Quick Union
  protected:
	int *id;
	int count;

  public:
	unionFind() {}
	~unionFind() {}
	virtual int find(int p) = 0;
	bool isConnected(int p, int q);
};
