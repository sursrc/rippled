#include "Offer.h"

AccountItem::pointer Offer::makeItem(const uint160& ,SerializedLedgerEntry::ref ledgerEntry)
{
	if (!mLedgerEntry || mLedgerEntry->getType() != ltOFFER) return(AccountItem::pointer());
	Offer* offer=new Offer(ledgerEntry);
	return(AccountItem::pointer(offer));
}

Offer::Offer(SerializedLedgerEntry::pointer ledgerEntry) : AccountItem(ledgerEntry)
{
	mAccount=mLedgerEntry->getFieldAccount(sfAccount);
	mTakerGets		= mLedgerEntry->getFieldAmount(sfTakerGets);
	mTakerPays		= mLedgerEntry->getFieldAmount(sfTakerPays);
}