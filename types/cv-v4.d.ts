export class cvMatObject {
  constructor();
  constructor(rows: number, cols: number);

  readonly rows: number;
  readonly cols: number;
  readonly type: number;
  readonly depth: number;
  readonly isContinuous: boolean;
  readonly isSubmatrix: boolean;
  readonly elemSize: number;
  readonly elemSize1: number;

  // not exported
  // release(): void;
}

export function imread(filename: string): cvMatObject;