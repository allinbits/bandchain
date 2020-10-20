module CreateValidatorMsg = {
  [@react.component]
  let make = (~validator: TxSub.Msg.CreateValidator.t) => {
    <Row.Grid>
      <Col.Grid col=Col.Six mb=24>
        <Heading value="Monikor" size=Heading.H5 marginBottom=8 />
        <ValidatorMonikerLink
          validatorAddress={validator.validatorAddress}
          moniker={validator.moniker}
          identity={validator.identity}
          width={`percent(100.)}
          avatarWidth=20
          size=Text.Lg
          weight=Text.Thin
        />
      </Col.Grid>
      <Col.Grid col=Col.Six mb=24>
        <Heading value="Identity" size=Heading.H5 marginBottom=8 />
        <Text size=Text.Lg value={validator.identity} weight=Text.Thin code=true />
      </Col.Grid>
      <Col.Grid col=Col.Six mb=24>
        <Heading value="Commission Rate" size=Heading.H5 marginBottom=8 />
        <Text
          size=Text.Lg
          value={validator.commissionRate->Js.Float.toFixedWithPrecision(~digits=4) ++ "%"}
          weight=Text.Thin
          code=true
        />
      </Col.Grid>
      <Col.Grid col=Col.Six mb=24>
        <Heading value="Commission Max Rate" size=Heading.H5 marginBottom=8 />
        <Text
          size=Text.Lg
          value={validator.commissionMaxRate->Js.Float.toFixedWithPrecision(~digits=4) ++ "%"}
          weight=Text.Thin
          code=true
        />
      </Col.Grid>
      <Col.Grid col=Col.Twelve mb=24>
        <Heading value="Commission Max Change" size=Heading.H5 marginBottom=8 />
        <Text
          size=Text.Lg
          value={validator.commissionMaxChange->Js.Float.toFixedWithPrecision(~digits=4) ++ "%"}
          weight=Text.Thin
          code=true
        />
      </Col.Grid>
      <Col.Grid col=Col.Six mb=24>
        <Heading value="Delegator Address" size=Heading.H5 marginBottom=8 />
        <AddressRender position=AddressRender.Subtitle address={validator.delegatorAddress} />
      </Col.Grid>
      <Col.Grid col=Col.Six mb=24>
        <Heading value="Validator Address" size=Heading.H5 marginBottom=8 />
        <AddressRender
          position=AddressRender.Subtitle
          address={validator.validatorAddress}
          accountType=`validator
        />
      </Col.Grid>
      <Col.Grid col=Col.Twelve mb=24>
        <Heading value="Public Key" size=Heading.H5 marginBottom=8 />
        <PubKeyRender pubKey={validator.publicKey} alignLeft=true position=PubKeyRender.Subtitle />
      </Col.Grid>
      <Col.Grid col=Col.Six mb=24>
        <Heading value="Min Self Delegation" size=Heading.H5 marginBottom=8 />
        <AmountRender coins=[validator.minSelfDelegation] pos=AmountRender.TxIndex />
      </Col.Grid>
      <Col.Grid col=Col.Six mb=24>
        <Heading value="Self Delegation" size=Heading.H5 marginBottom=8 />
        <AmountRender coins=[validator.selfDelegation] pos=AmountRender.TxIndex />
      </Col.Grid>
      <Col.Grid col=Col.Twelve mb=24>
        <Heading value="Details" size=Heading.H5 marginBottom=8 />
        <Text size=Text.Lg weight=Text.Thin value={validator.details} />
      </Col.Grid>
      <Col.Grid col=Col.Twelve mb=24>
        <Heading value="Website" size=Heading.H5 marginBottom=8 />
        <Text size=Text.Lg weight=Text.Thin value={validator.website} />
      </Col.Grid>
    </Row.Grid>;
  };
};

module EditValidatorMsg = {
  [@react.component]
  let make = (~validator: BandScan.TxSub.Msg.EditValidator.t) => {
    <Row.Grid>
      <Col.Grid col=Col.Six mb=24>
        <Heading value="Monikor" size=Heading.H5 marginBottom=8 />
        <Text
          value={validator.moniker == Config.doNotModify ? "Unchanged" : validator.moniker}
          size=Text.Lg
          weight=Text.Thin
          code=true
        />
      </Col.Grid>
      <Col.Grid col=Col.Six mb=24>
        <Heading value="Identity" size=Heading.H5 marginBottom=8 />
        <Text
          size=Text.Lg
          value={validator.identity == Config.doNotModify ? "Unchanged" : validator.identity}
          weight=Text.Thin
          code=true
        />
      </Col.Grid>
      <Col.Grid col=Col.Six mb=24>
        <Heading value="Commission Rate" size=Heading.H5 marginBottom=8 />
        <Text
          size=Text.Lg
          value={
            switch (validator.commissionRate) {
            | Some(rate) => rate->Js.Float.toFixedWithPrecision(~digits=4) ++ "%"
            | None => "Unchanged"
            }
          }
          weight=Text.Thin
          code=true
        />
      </Col.Grid>
      <Col.Grid col=Col.Six mb=24>
        <Heading value="Validator Address" size=Heading.H5 marginBottom=8 />
        <AddressRender
          position=AddressRender.Subtitle
          address={validator.sender}
          accountType=`validator
        />
      </Col.Grid>
      <Col.Grid col=Col.Twelve mb=24>
        <Heading value="Min Self Delegation" size=Heading.H5 marginBottom=8 />
        {switch (validator.minSelfDelegation) {
         | Some(minSelfDelegation') =>
           <AmountRender coins=[minSelfDelegation'] pos=AmountRender.TxIndex />
         | None => <Text value="Unchanged" code=true size=Text.Lg weight=Text.Thin />
         }}
      </Col.Grid>
      <Col.Grid col=Col.Twelve mb=24>
        <Heading value="Details" size=Heading.H5 marginBottom=8 />
        <Text
          size=Text.Lg
          weight=Text.Thin
          value={validator.details == Config.doNotModify ? "Unchanged" : validator.details}
        />
      </Col.Grid>
    </Row.Grid>;
  };
};

// module UnjailMsg = {};

module AddReporterMsg = {
  [@react.component]
  let make = (~address: TxSub.Msg.AddReporter.success_t) => {
    <Row.Grid>
      <Col.Grid col=Col.Six mb=24>
        <Heading value="Validator" size=Heading.H5 marginBottom=8 />
        <Text value={address.validatorMoniker} code=true />
      </Col.Grid>
      <Col.Grid col=Col.Six mb=24>
        <Heading value="Reporter Address" size=Heading.H5 marginBottom=8 />
        <AddressRender address={address.reporter} />
      </Col.Grid>
    </Row.Grid>;
  };
};

// module RemoveReporterMsg = {};

// module ActivateMsg = {};

// module SetWithdrawAddressMsg = {};