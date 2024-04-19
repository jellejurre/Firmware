// automatically generated by the FlatBuffers compiler, do not modify

/* eslint-disable @typescript-eslint/no-unused-vars, @typescript-eslint/no-explicit-any, @typescript-eslint/no-non-null-assertion */

import * as flatbuffers from 'flatbuffers';

import { SetGPIOResultCode } from '../../../open-shock/serialization/local/set-gpioresult-code';


export class SetRfTxPinCommandResult {
  bb: flatbuffers.ByteBuffer|null = null;
  bb_pos = 0;
  __init(i:number, bb:flatbuffers.ByteBuffer):SetRfTxPinCommandResult {
  this.bb_pos = i;
  this.bb = bb;
  return this;
}

pin():number {
  return this.bb!.readUint8(this.bb_pos);
}

result():SetGPIOResultCode {
  return this.bb!.readUint8(this.bb_pos + 1);
}

static sizeOf():number {
  return 2;
}

static createSetRfTxPinCommandResult(builder:flatbuffers.Builder, pin: number, result: SetGPIOResultCode):flatbuffers.Offset {
  builder.prep(1, 2);
  builder.writeInt8(result);
  builder.writeInt8(pin);
  return builder.offset();
}

}
